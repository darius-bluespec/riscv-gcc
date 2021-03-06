
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_sound_midi_alsa_AlsaOutputPortDevice__
#define __gnu_javax_sound_midi_alsa_AlsaOutputPortDevice__

#pragma interface

#include <gnu/javax/sound/midi/alsa/AlsaPortDevice.h>
extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace sound
      {
        namespace midi
        {
          namespace alsa
          {
              class AlsaMidiDeviceProvider$AlsaPortInfo;
              class AlsaOutputPortDevice;
          }
        }
      }
    }
  }
  namespace javax
  {
    namespace sound
    {
      namespace midi
      {
          class Receiver;
          class Transmitter;
      }
    }
  }
}

class gnu::javax::sound::midi::alsa::AlsaOutputPortDevice : public ::gnu::javax::sound::midi::alsa::AlsaPortDevice
{

public: // actually package-private
  AlsaOutputPortDevice(::gnu::javax::sound::midi::alsa::AlsaMidiDeviceProvider$AlsaPortInfo *);
public:
  virtual void open();
  virtual void close();
  virtual jboolean isOpen();
  virtual jlong getMicrosecondPosition();
  virtual jint getMaxReceivers();
  virtual jint getMaxTransmitters();
  virtual ::javax::sound::midi::Receiver * getReceiver();
  virtual ::javax::sound::midi::Transmitter * getTransmitter();
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_sound_midi_alsa_AlsaOutputPortDevice__
