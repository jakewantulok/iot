# The Internet of Things ✨

## Grove Starter Kit for Particle Mesh 🌱

### Particle Jukebox 🎹

This is a fully functioning demo for **[The Grove Starter Kit for Particle Mesh](https://store.particle.io/products/grove-starter-kit)**. It also demonstrates how to use [`Particle.function()`](https://docs.particle.io/reference/device-os/firmware/photon/#cloud-functions). Just *⚡️flash* this to your Particle Argon and have fun! 
    
### Requirements:

- One claimed Particle Argon
- Grove shield for Particle Argon (with the argon in place)
    - Grove Starter Kit for Particle Mesh
        - Button ~ plugged into grove shield (D2)
        - Buzzer ~ plugged into grove shield (D4)
- USB Cable & Internet! (Duh)

#### Additional Notes:

Right now this is written assuming the button is plugged in. When unplugged, you will soon hear all of the tunes in a loop.
    
I highly recommend commenting out:
- `#define BTN D2` at the top
- `pinMode(BTN, INPUT);` in your `void setup()`
- Everything inside `void loop()`

I also would like to condense this down to only one function, but at the moment not sure how. This would greatly decrease the size of this sketch.
