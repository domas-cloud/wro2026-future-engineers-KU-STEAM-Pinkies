from dataclasses import dataclass


@dataclass
class Pillar:
    """Detected traffic pillar in camera coordinates."""

    x: int = 0
    y: int = 0
    w: int = 0
    h: int = 0
    cx: int = 0
    cy: int = 0
    area: float = 0.0
    color: str = "NONE"

    @property
    def is_valid(self) -> bool:
        return self.area > 0
