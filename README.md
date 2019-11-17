# The Internet of Things ✨

## Grove Starter Kit for Particle Mesh 🌱

### Particle Jukebox 🎹

`particlejukebox.ino` is a fully functioning demo for **[The Grove Starter Kit for Particle Mesh](https://store.particle.io/products/grove-starter-kit)**. It also demonstrates how to use [`Particle.function()`](https://docs.particle.io/reference/device-os/firmware/photon/#cloud-functions). Just *flash ⚡️* this sketch to your Particle Argon and see how it works! 
    
#### Requirements:

- One claimed Particle Argon
- Grove Starter Kit for Particle Mesh
    - Grove shield for Particle Argon
    - Button ~ plugged into grove shield `D2`
    - Buzzer ~ plugged into grove shield `D4`
- USB Cable & Internet! (duh)

#### Tunes 🎶 

After you have uploaded `particlejukebox.ino` to your Particle Argon, you will find "playTune" located in the **Functions** section in your [console](https://login.particle.io/login?redirect=https://console.particle.io/). (It's also handy to control your Particle Argon using the [app!](https://apps.apple.com/us/app/particle-iot/id991459054)) Enter any of the following to listen:

- Pokémon
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

#### Composition

This template is already written as a comment at the very bottom of `particlejukebox.ino`.

```C++
int playThisTune() {

    int melody[] = {0};
    int melodySeq[] = {0};
    
    for (int note = 0; note < X; note++) {
      int duration = 1000/melodySeq[note];
      tone(BZZ, melody[note], duration);
      delay(duration * 1.30);
    }
    tune++;
}
```

There are only three parts needed for alteration:
- `int melody[]`
- `int melodySeq[]`
- `note < X` in your ***for*** loop

`int melody[]` requires an arrangement of notes. For regular notes you will need to write in lowercase (`a`) and a sharp in uppercase (`A`). 

```C++
int pokemon[] = {d,f,g};
```

However, in some cases you might need one note at a higher or lower octave. Just write whatever note with `*2` or `/2`

```C++
int indianaJones[] = {d,D,f,A*2,d,f,D}; // (with a# one octave above)
```

`int melodySeq` is used to create the rhythm to your melody. It can be a little tricky, but the numbers given to the array should make sense for someone familiar to playing an instrument. There are whole `1`, quarter `4`, eighth `8` etc. You will see a few variances in this sketch such as `6`, `12`, and `3`. This was intended to slow down the melody without altering the loop. Smooth Criminal is an example of this. (You can also play around with different time signatures, if you know what you're doing) 

You can also add pauses to your tune by adding `0`.

```C++
int mario[] =    {e,e,e,d,e,g,0,g/2};
int marioSeq[] = {8,8,4,8,4,4,4,  4};
```

The key to getting your tune working correctly is to make sure `melody[]` & `melody[]` are equal in size. It's also important to replace `X` with the number of notes in your tune. I added this `X` for the Particle IDE to remind you. :)

#### Additional Notes:

This was written with the button connected. Once the button has been removed, you will immediately hear every tune play in a continuous loop. I highly recommend commenting out the following if you wish to control your Particle Argon using only the Particle Cloud Function:
- `#define BTN D2` at the top
- `pinMode(BTN, INPUT);` in your `void setup()`
- Everything inside `void loop()`
