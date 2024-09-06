# LinFax
linfax is taken from hamfax, HF Weather Fax

## How to compile

Dependencies:
- portaudio
- audiofile
- qt6

On debian : `apt install libaudiofile-dev libportaudio2 qt6-base-dev qmake6`

Simply run
```bash
qmake6
make -j$(nproc)
```