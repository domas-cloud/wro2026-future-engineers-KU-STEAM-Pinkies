#ifndef LIDAR_H
#define LIDAR_H

#include <Arduino.h>
#include <Wire.h>
#include <VL53L1X.h>
#include <RunningAverage.h>

struct Distance_Result {
    int distance;
    uint8_t status;
};

class Distance_Sensor {
    private:
        int8_t _xshut;
        VL53L1X _sensor;
        RunningAverage _filter;

    public:
        Distance_Sensor() : _xshut(-1), _filter(3) {}

        bool begin(int8_t xshut, uint8_t newAddress) {
            _xshut = xshut;

            pinMode(_xshut, OUTPUT);
            digitalWrite(_xshut, HIGH);
            delay(50);

            if (!_sensor.init()) {
                return false;
            }

            _sensor.setAddress(newAddress);
            _sensor.setDistanceMode(VL53L1X::Long);
            _sensor.setMeasurementTimingBudget(50000);
            _sensor.startContinuous(50);
            return true;
        }

        Distance_Result measureDistance() {
            Distance_Result result = {0, 255};
            const int measurement = _sensor.read();

            if (!_sensor.timeoutOccurred()) {
                result.status = _sensor.ranging_data.range_status;
                _filter.addValue(measurement);
            }

            if (_filter.getCount() > 0) {
                result.distance = static_cast<int>(_filter.getAverage());
            }

            return result;
        }
};

#endif
