#pragma once

#include <pico/printf.h>
#include "ZxSpectrumJoystick.h"

class ZxSpectrumHidMouseJoystick : public ZxSpectrumJoystick {
private:
  // Joystick stuff
  uint8_t _kempston;
  uint8_t _sinclairL;
  uint8_t _sinclairR;
  bool _isLeft;
  // Mouse stuff
  int32_t _xAcc;
  int32_t _yAcc;
  int32_t _wAcc;
  uint8_t _mounted;
  uint8_t _buttons;
 //uint32_t _us;
  int32_t _xp;
  int32_t _yp;
  //-----------
  bool left;
  bool right;
  bool up;
  bool down;
  //-----------
public:
  ZxSpectrumHidMouseJoystick();
  void __not_in_flash_func(decode)();
  virtual uint8_t __not_in_flash_func(kempston)();
  virtual uint8_t __not_in_flash_func(sinclairL)();
  virtual uint8_t __not_in_flash_func(sinclairR)();
  virtual bool __not_in_flash_func(isConnectedL)();
  virtual bool __not_in_flash_func(isConnectedR)();
  inline void xDelta(int32_t xd) { _xAcc += xd; }
  inline void yDelta(int32_t yd) { _yAcc -= yd; }
  inline void wDelta(int32_t wd) { _wAcc += wd; }
  void setButtons(uint32_t b);  

  bool isMounted() { return _mounted > 0; }
  inline void mount() { _mounted++; }
  inline void unmount() { _mounted--; }  
};
