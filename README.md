# cse471_project1

## group members: charles moshier

## Format of .score files
```xml
<?xml version="1.0" encoding="utf-8"?>
<score bpm="120" beatspermeasure="2">
  <instrument instrument="ToneInstrument">
    <note measure="1" beat="2" duration="0.33" note="F4"/>
  </instrument>
  <instrument instrument="Ringmod">
    <note measure="1" beat="2" wet="0.7" dry="0.5" delay=".02" duration=".02"/>
  </instrument>
</score>
```

| tag | Description | options |
| ----------- | ----------- | ----------- |
| score | base score node | bpm,beatspermeasure |
| instrument | instrument object| instrument=type (ToneInstrument or one of the effects)|
| instrument | effect types | instrument=type (Ringmod,Flanger,Chorus)|
| note | data to pass into the instrument | measure(what measure),beat(what beat),wet(wet signal amount),dry(dry signal amount),delay(delay paramater),duration(note/effect duration)

## Score File
[Main Selection](https://github.com/moshier1/cse471_project1/blob/main/final.score)
## Selection Audio File
[Main Selection](https://github.com/moshier1/cse471_project1/blob/main/selection2.wav)
### Effect Audio Files
[Chorus](https://github.com/moshier1/cse471_project1/blob/main/chorus.wav)

[Flanger](https://github.com/moshier1/cse471_project1/blob/main/flanger.wav)

[Ringmod](https://github.com/moshier1/cse471_project1/blob/main/ringmod.wav)
