## Signals and slots
- A `slot` remains an *ordinary* function, so you can call it yourself.
- A single `signal` can be linked to different slots.
- A single `slot` can be called by different linked `signals`.
- A `connection` can be made between a signal and a slot from different objects, and even between objects living inside different threads.
