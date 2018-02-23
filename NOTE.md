## Signals and slots
- A `slot` remains an *ordinary* function, so you can call it yourself.
- A single `signal` can be linked to different slots.
- A single `slot` can be called by different linked `signals`.
- A `connection` can be made between a signal and a slot from different objects, and even between objects living inside different threads.


## Custom widget
In order to indicate how your widgets should be laid out and how they should
react when the window geometry changes (for example, when the user resizes the window).
For this, Qt has several default layout classes:
- `Vertical Layout`: In this layout, widgets are vertically stacked.
- `Horizontal Layout`: In this layout, widgets are horizontally stacked.
- `Grid Layout`: In this layout, widgets are arranged in a grid that can be subdivided into smaller cells.
- `Form Layout`: In this layout, widgets are arranged like a web form, a label, and an input.

Every layout will try to constrain all widgets to occupy equal surfaces.
It will either change the widget's shape or add extra margins, depending on
each widget's constaints (e.g. A check box will not be stretched but a Push Button will).

## Adding a Task
- Do you often need to insert objects larger than a pointer at the beginning or in the middle of your
array? -> Use a `QList` class
- Need contiguous memory allocation? Less CPU and memory overhead? Use a `QVector` class.

