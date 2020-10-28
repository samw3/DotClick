# The Dot Click Computer
>Draw dots, click your speaker, make something cool.

###Are you up for a challenge?  

Dot Click is a very simplistic virtual computer operated by a single function called 705,600 times per second.

    uint8_t dot_click(uint16_t dot, uint8_t input)
    {
        uint8_t output = ... your code here ...
        return output;
    }

### The `dot` parameter
The Dot Click computer processes **11,760 dot-click bytes** 60 times per second. The first 9216 values of `dot` are pixels on the screen.  The dot-click byte is split into two sections, a `dot` section and a `click` section.  

9,216 of those dots are visible on the display.  The remaining 2,544 dots are not visible, but audio is still processed for these output values.

### The `input` parameter
Use this to read the user's controller and cursor.  Each bit is set to 1 when the corresponding button is pressed.  Bit 7 is set to 1 when the cursor is on the current dot.
- bit 0 : press up
- bit 1 : press down
- bit 2 : press left
- bit 3 : press right
- bit 4 : press A (Z, space, enter)
- bit 5 : press B (X, esc)
- bit 6 : click the cursor
- bit 7 : cursor is here

### The `dot_click` return value
- bits 0-3 speaker volume
    - Use these bits to make sounds.  *Try this:* `output=(dot>>9)&1)<<3;`

- bits 4-7 dot color
    - Use these bits to color a dot on the screen. *Try this:* `output=(dot<<1)&0xf0;`