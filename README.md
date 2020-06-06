# mbed-os-retarget-segger-rtt

This is a FileHandle interface implementation and retarget registration of the stdio interface to the Segger Real-Time Terminal (RTT) instead of the default serial port.

Further information about the background of the implementation can be found in [Pull Request #5356](https://github.com/ARMmbed/mbed-os/pull/5356) and [Pull Request #5571](https://github.com/ARMmbed/mbed-os/pull/5571).

## Requirements

Requires JLink debug probe.

## Configuration

In your `mbed_app.json` you can control the default override behavior of this library:

```json
{
  "target_overrides": {
    "*": {
      "mbed-segger-rtt.override_console": true
    }
}
```

* true: use Segger RTT as mbed-os console. It will Just Work, there is nothing else you need to do.
* false: use the  mbed-os default console. You can still use Segger RTT as second console, see below.

## Use Segger  RTT as second console

When you want to keep the default mbed-os console and use Segger RTT as second console make sure
that `mbed-segger-rtt.override_console` is set to `false`.
Next in your code you can easily instantiate a Segger RTT console object:

```c
static SeggerRTT fhSeggerRtt;
```

## Usage

Download the JLinkExe and JLinkClient from [Segger.com](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack).
Install tools, on Ubuntu:

```bash
sudo alien -i ./JLink_Linux_V680a_x86_64.rpm
```

Open de JLink server in one terminal:

```bash
$ JLinkExe -device nrf52 -if swd -speed 4000 -autoconnect 1
SEGGER J-Link Commander V6.80a (Compiled May 29 2020 16:30:49)
DLL version V6.80a, compiled May 29 2020 16:30:38
```

In a escond terminal launch the Jlink client:

```bash
JLinkRTTClient
```
