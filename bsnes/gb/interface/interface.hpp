#ifndef GB_HPP
namespace GameBoy {
#endif

struct ID {
  enum : unsigned {
    GameBoyBootROM,
    SuperGameBoyBootROM,
    GameBoyColorBootROM,
    GameBoyROM,
    GameBoyColorROM,
    RAM,
  };

  enum : unsigned {
    Device = 1,
  };
};

struct Interface : Emulator::Interface {
  //Super Game Boy bindings
  virtual void lcdScanline() {}
  virtual void joypWrite(bool p15, bool p14) {}

  bool loaded();
  string sha256();
  void load(unsigned id, const stream &stream, const string &markup = "");
  void save(unsigned id, const stream &stream);
  void unload();

  void power();
  void reset();
  void run();

  serializer serialize();
  bool unserialize(serializer&);

  void cheatSet(const lstring&);

  void updatePalette();

  Interface();
};

extern Interface *interface;

#ifndef GB_HPP
}
#endif