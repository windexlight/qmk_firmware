# Ploopyco

* [Mouse](mouse/)
* [Trackball](trackball/)
* [Trackball Mini](trackball_mini/)
* [Trackball Nano](trackball_nano/)
* [Trackball Thumb](trackball_thumb/)
* [Adept/Madromys](madromys/)

# Customizing your PloopyCo Device

There are a number of behavioral settings that you can use to help customize your experience
|Define                         |Default Value|Description                                              |
|-------------------------------|-------------|---------------------------------------------------------|
|`PLOOPY_IGNORE_SCROLL_CLICK`   |*Not defined*|Ignores scroll wheel if it is pressed down.              |
|`PLOOPY_SCROLL_DEBOUNCE`       |`5`          |Number of milliseconds between scroll events.            |
|`PLOOPY_SCROLL_BUTTON_DEBOUNCE`|`100`        |Time to ignore scroll events after pressing scroll wheel.|

## DPI

You can change the DPI/CPI or speed of the trackball by calling `pointing_device_set_cpi` at any time. Additionally, there is a `DPI_CONFIG` macro that will cycle through an array of options for the DPI.  This is set to 1200, 1600, and 2400, but can be changed.  1600 is also set to the default.

To configure/set your own array, there are two defines to use, `PLOOPY_DPI_OPTIONS` to set the array, and `PLOOPY_DPI_DEFAULT`.

```c
#define PLOOPY_DPI_OPTIONS { 1200, 1600, 2400 }
#define PLOOPY_DPI_DEFAULT 1
```

The `PLOOPY_DPI_OPTIONS` array sets the values that you want to be able to cycle through, and the order they are in.  The "default" define lets the firmware know which of these options is the default and should be loaded by default.

The `DPI_CONFIG` custom keycode will cycle through the values in the array, each time you hit it. And it stores this value in persistent memory, so it will load it the next time the device powers up.

## Drag Scroll

Drag Sroll is a custom keycode for the Ploopy devices that allow you to hold or tap a button and have the mouse movement translate into scrolling instead.

Nothing needs to be enabled to use this functionality.  Just add `DRAG_SCROLL` to your keymap.

### Drag Scroll Configuration

* `#define PLOOPY_DRAGSCROLL_MOMENTARY` - Makes the key into a momentary key, rather than a toggle.
* `#define PLOOPY_DRAGSCROLL_INVERT` - This reverses the direction that the scroll is performed.

These are new for the High Resolution Scrolling Mod:
* `#define PLOOPY_DRAGSCROLL_H_COEF 1.0` - Scale applied to horizontal scrolling. For example, 0.5 would make horizontal scrolling half as sensitive as vertical scrolling.
* `#define PLOOPY_SCROLL_DIV_OPTIONS { 0.5, 1.0, 1.5, 2.0, 4.0 }` - Array of divisors applied to movement for scrolling. In other words, scrolling sensitivity options, to be cycled through using the `SCROLL_DIV_CONFIG` custom keycode. Higher is less sensitive. Like `DPI_CONFIG`, the current setting is stored in persistent memory, so it will be saved across power cycles.
* `#define PLOOPY_SCROLL_DIV_DEFAULT 0` - The default index into `PLOOPY_SCROLL_DIV_OPTIONS`, meaning the default scrolling sensitivity.

### Custom Keycodes Added by High Resolution Scrolling Mod

Note that these custom keycodes are not currently known by VIA, as they are not standard for PloopyCo official firmware. In order to use them in VIA, you must select SPECIAL -> Any, and enter CUSTOM(n), where n is the ordinal value of the custom keycode. These are specified below.

* `SCROLL_DIV_CONFIG` - `CUSTOM(2)` - Cycles through scroll sensitivty options with each press. State is saved to persistent memory, so will be saved across power cycles.
* `HIRES_SCROLL` - `CUSTOM(3)` - Toggle high resolution scrolling on and off. The QMK implementation of high resolution scrolling currently does not allow for dynamic enable/disable of high resolution scrolling (in other words, changing the scrolling resolution reported to the host dynamically). In order to emulate disablement of hires scrolling, the firmware will report scrolling events only in increments of the statically defined scrolling resolution.
* `SCROLL_SNAP_V` - `CUSTOM(4)` - Toggles vertical scroll snap on and off. When on, horizontal scrolling is disabled. When turned on, horizontal scroll snap will be turned off.
* `SCROLL_SNAP_H` - `CUSTOM(5)` - Toggles horizontal scroll snap on and off. When on, vertical scrolling is disabled. When turned on, vertical scroll snap will be turned off.
