import string
import enum

class logger:
  class level(enum.Enum):
    DEBUG = 5
    ERROR = 4
    WARNING = 3
    INFO = 2
    NONE = 1
  def __init__(self, log_level: level):
     self.log_level: self.level = log_level


  def log(self, message: str, level: level):
    if (self.log_level == self.level.DEBUG and (level == self.level.DEBUG or level == self.level.ERROR or level == self.level.WARNING or level == self.level.INFO)):
      if level == self.level.ERROR:
        print(f"\033[91m{message}\033[00m")
        return 0
      elif level == self.level.WARNING:
        print(f"\033[93m{message}\033[00m")
        return 0
      elif level == self.level.INFO:
        print(f"{message}")
        return 0
      elif level == self.level.DEBUG:
        print(f"\033[94m{message}\033[00m")
        return 0
      else:
        print(f"ERROR: Invalid Log Level\n{message}")
        return 1
    elif (self.log_level == self.level.ERROR and (level == self.level.ERROR or level == self.level.WARNING or level == self.level.INFO)):
      if level == self.level.ERROR:
        print(f"\033[91m{message}\033[00m")
        return 0
      elif level == self.level.WARNING:
        print(f"\033[93m{message}\033[00m")
        return 0
      elif level == self.level.INFO:
        print(f"{message}")
        return 0
      elif level == self.level.DEBUG:
        print(f"\033[94m{message}\033[00m")
        return 0
      else:
        print(f"ERROR: Invalid Log Level\n{message}")
        return 1
      
    elif (self.log_level == self.level.WARNING and (level == self.level.WARNING or level == self.level.INFO)):
      if level == self.level.ERROR:
        print(f"\033[91m{message}\033[00m")
        return 0
      elif level == self.level.WARNING:
        print(f"\033[93m{message}\033[00m")
        return 0
      elif level == self.level.INFO:
        print(f"{message}")
        return 0
      elif level == self.level.DEBUG:
        print(f"\033[94m{message}\033[00m")
        return 0
      else:
        print(f"ERROR: Invalid Log Level\n{message}")
        return 1
    elif (self.log_level == self.level.INFO and level == self.level.INFO):
      if level == self.level.ERROR:
        print(f"\033[91m{message}\033[00m")
        return 0
      elif level == self.level.WARNING:
        print(f"\033[93m{message}\033[00m")
        return 0
      elif level == self.level.INFO:
        print(f"{message}")
        return 0
      elif level == self.level.DEBUG:
        print(f"\033[94m{message}\033[00m")
        return 0
      else:
        print(f"ERROR: Invalid Log Level\n{message}")
        return 1
    elif (self.log_level == self.level.NONE):
      return 0
    else:
      print("ERROR: Invalid Log Level")
      return 1