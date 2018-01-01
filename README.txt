
This tool is used to parse PCM data, T38 data， convert PCM raw bin format to WAV format and simulate IPFAX terminal.

How to compile and install the tool:

-> cd build
-> make && make install

How to use the tool

1. Parse PCM data.

Usage: pcm_parse -i filename

2. Parse T38 data.

Usage: t38_pcap_parse 
                   -i filename: input pcap file name, mandatory
                   -e: using ecm, default is non-ecm, optional
                   -v: giving t38 version, default is 0, optional
                   -S: source address, optional
                   -s: source port, optional
                   -D: destination address, optional
                   -d: destination port, optional
                   
3. Tone detect

Usage: modem_connect_tones_detect -d tone_file

4. Convert PCM raw bin format to wav format.

Usage: pcm_parse -b filename.bin

5. Simulate IPFAX terminal.

Ongoing
