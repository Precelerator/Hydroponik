//Pictures

// 'Precelerator', 126x13px
const unsigned char precelerator [] PROGMEM = {
  0xfe, 0x1f, 0xc3, 0xfc, 0x1e, 0x1f, 0xe7, 0x01, 0xfe, 0xfe, 0x01, 0x87, 0xfe, 0x1e, 0x07, 0xe0, 
  0xff, 0x1f, 0xe3, 0xfc, 0x7f, 0x9f, 0xf7, 0x03, 0xfe, 0xff, 0x83, 0xc7, 0xfe, 0x3f, 0x8f, 0xf8, 
  0xe3, 0x9c, 0x73, 0x80, 0xe3, 0x9c, 0x07, 0x03, 0x80, 0xe3, 0x83, 0xc0, 0x70, 0x71, 0xce, 0x38, 
  0xe1, 0x9c, 0x33, 0x80, 0xe1, 0xdc, 0x07, 0x03, 0x80, 0xe1, 0x83, 0xc0, 0x60, 0xe1, 0xce, 0x1c, 
  0xe1, 0x9c, 0x33, 0x80, 0xc0, 0x1c, 0x07, 0x03, 0x80, 0xe1, 0x87, 0xe0, 0x60, 0xe0, 0xce, 0x18, 
  0xe3, 0x9c, 0x73, 0xfc, 0xc0, 0x1f, 0xe7, 0x03, 0xfc, 0xe3, 0x86, 0x60, 0x60, 0xe0, 0xee, 0x38, 
  0xff, 0x9f, 0xe3, 0xfc, 0xc0, 0x1f, 0xe7, 0x03, 0xfc, 0xff, 0x0e, 0x70, 0x60, 0xe0, 0xef, 0xf8, 
  0xff, 0x1f, 0xc3, 0x80, 0xc0, 0x1c, 0x07, 0x03, 0x80, 0xfe, 0x0e, 0x70, 0x60, 0xe0, 0xcf, 0xf0, 
  0xe0, 0x1c, 0xe3, 0x80, 0xc1, 0x9c, 0x07, 0x03, 0x80, 0xe7, 0x0f, 0xf0, 0x60, 0xe0, 0xce, 0x70, 
  0xe0, 0x1c, 0x63, 0x80, 0xe1, 0x9c, 0x07, 0x03, 0x80, 0xe3, 0x1f, 0xf8, 0x60, 0x61, 0xce, 0x30, 
  0xe0, 0x1c, 0x73, 0xfc, 0x77, 0x9f, 0xe7, 0xfb, 0xfc, 0xe3, 0x9c, 0x38, 0x60, 0x7b, 0x8e, 0x38, 
  0xe0, 0x1c, 0x33, 0xfe, 0x7f, 0x1f, 0xf7, 0xfb, 0xfe, 0xe1, 0x98, 0x18, 0x60, 0x3f, 0x8e, 0x1c, 
  0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00
};
// 'waterdrop', 15x20px
const unsigned char tempWater [] PROGMEM = {
  0x01, 0x00, 0x01, 0x00, 0x03, 0x80, 0x03, 0x80, 0x07, 0xc0, 0x07, 0xe0, 0x0f, 0xe0, 0x0f, 0xf0,
  0x1f, 0xf0, 0x1f, 0xf0, 0x3f, 0xf8, 0x3f, 0xf8, 0x3f, 0xf8, 0x3f, 0xf8, 0x3f, 0xf8, 0x3f, 0xf8,
  0x1f, 0xf0, 0x1f, 0xf0, 0x0f, 0xe0, 0x03, 0x80
};

// 'Temp', 15x20px
const unsigned char airTemp [] PROGMEM = {
  0x03, 0x80, 0x04, 0x40, 0x08, 0x20, 0x08, 0x20, 0x08, 0x20, 0x08, 0x20, 0x08, 0x20, 0x08, 0x20,
  0x08, 0x20, 0x0b, 0xa0, 0x0b, 0xa0, 0x0b, 0xa0, 0x13, 0x90, 0x27, 0xc8, 0x4f, 0xe4, 0x5f, 0xf4,
  0x4f, 0xe4, 0x27, 0xc8, 0x10, 0x10, 0x0f, 0xe0
};



// 'WaterFull', 15x20px
const unsigned char waterFull [] PROGMEM = {
  0x1f, 0xf0, 0x08, 0x20, 0x08, 0x20, 0x10, 0x10, 0x25, 0x48, 0x4f, 0xe4, 0x5f, 0xf4, 0x9f, 0xf2,
  0xbf, 0xfa, 0xbf, 0xfa, 0xbf, 0xfa, 0xbf, 0xfa, 0xbf, 0xfa, 0xbf, 0xfa, 0xbf, 0xfa, 0xbf, 0xfa,
  0xbf, 0xfa, 0x9f, 0xf2, 0x40, 0x04, 0x7f, 0xfc
};
// 'WaterHalf', 15x20px
const unsigned char waterHalf [] PROGMEM = {
  0x1f, 0xf0, 0x08, 0x20, 0x08, 0x20, 0x10, 0x10, 0x20, 0x08, 0x40, 0x04, 0x40, 0x04, 0x80, 0x02,
  0x80, 0x02, 0x80, 0x02, 0x95, 0x52, 0xbf, 0xfa, 0xbf, 0xfa, 0xbf, 0xfa, 0xbf, 0xfa, 0xbf, 0xfa,
  0xbf, 0xfa, 0x9f, 0xf2, 0x40, 0x04, 0x7f, 0xfc
};
// 'WaterEmpty', 15x20px
const unsigned char waterEmpty [] PROGMEM = {
  0x1f, 0xf0, 0x08, 0x20, 0x08, 0x20, 0x10, 0x10, 0x20, 0x08, 0x40, 0x04, 0x40, 0x04, 0x80, 0x02,
  0x80, 0x02, 0x80, 0x02, 0x80, 0x02, 0x80, 0x02, 0x80, 0x02, 0x80, 0x02, 0x80, 0x02, 0x95, 0x52,
  0xbf, 0xfa, 0x9f, 0xf2, 0x40, 0x04, 0x7f, 0xfc
};

// 'Luftfeucht', 15x20px
const unsigned char waterHum [] PROGMEM = {
  0x01, 0x00, 0x03, 0x80, 0x03, 0x80, 0x07, 0xc0, 0x07, 0xc0, 0x0f, 0xe0, 0x0f, 0xe0, 0x1f, 0xf0,
  0x1f, 0xf0, 0x31, 0xd8, 0x35, 0x98, 0x71, 0x3c, 0x7e, 0x7c, 0xfc, 0xfe, 0xf9, 0x1e, 0xf3, 0x5e,
  0x77, 0x1c, 0x3f, 0xf8, 0x0f, 0xe0, 0x03, 0x80
};
// 'Batterie', 15x20px
const unsigned char batterie [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x3c, 0xff, 0xfe, 0x80, 0x02, 0x80, 0x02,
  0x88, 0x02, 0x88, 0x02, 0xbe, 0xfa, 0x88, 0x02, 0x88, 0x02, 0x80, 0x02, 0x80, 0x02, 0xff, 0xfe,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};