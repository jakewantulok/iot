# The Internet of Things ✨

## Grove Starter Kit for Particle Mesh 🌱

### Particle Jukebox 🎹

`particlejukebox.ino` is a fully functioning demo for **[The Grove Starter Kit for Particle Mesh](https://store.particle.io/products/grove-starter-kit)**. It also demonstrates how to use [`Particle.function()`](https://docs.particle.io/reference/device-os/firmware/photon/#cloud-functions). Just *⚡️flash* this sketch to your Particle Argon and see how it works! 
    
#### Requirements:

- One claimed Particle Argon
- Grove Starter Kit for Particle Mesh
    - Grove shield for Particle Argon (with the argon in place)
    - Button ~ plugged into grove shield `D2`
    - Buzzer ~ plugged into grove shield `D4`
- USB Cable & Internet! (Duh)

#### Tunes 🎶 

After you have uploaded `particlejukebox.ino` to your Particle Argon, you will find "playTune" located in the **Functions** section in the [console](https://login.particle.io/login?redirect=https://console.particle.io/). (It's also handy to control your Particle Argon using the [app!](https://apps.apple.com/us/app/particle-iot/id991459054)) Enter any of the following to listen:

- Pokêmon
- Kim Possible
- Power Rangers
- Sesame Street
- Smooth Criminal
- Star Wars
- Indiana Jones
- Mario Bros
- Legend of Zelda
- Example Melody

Also, this is the play order each time the button is pressed. When you finally hear the Example Melody, it will reset to the first tune.

#### Additional Notes:

This was written with the button connected. Once the button has been removed, you will immediately hear every tune play in a continuous loop.
    
I highly recommend commenting out the following if you wish to control your Particle Argon using only the Particle Cloud Function:
- `#define BTN D2` at the top
- `pinMode(BTN, INPUT);` in your `void setup()`
- Everything inside `void loop()`
