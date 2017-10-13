# pcap-extractor

PCAP data extractor

### Install deps
```
sudo apt install libwireshark-dev
sudo apt-get install libglib2.0-dev
```

### Build
```
g++ --std=c++11 -fPIC -shared -I/usr/include/wireshark -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -o http_extract_plugin.so http_extract_plugin.cpp
```

### Install
```
sudo cp http_extract_plugin.so /usr/lib/x86_64-linux-gnu/wireshark/plugins/2.2.6/
```

### Usage
```
tshark -r post.pcap >> /dev/null
```
