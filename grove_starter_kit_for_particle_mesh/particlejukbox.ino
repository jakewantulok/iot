#define BTN D2
#define BZZ D4

////////////////// PARTICLE JUKEBOX //////////////////

/*
    
    This is a fully functioning demo for "The Grove Starter Kit for Particle Mesh"
    Just flash this to your Particle Argon and have fun!
    
    This also demonstrates how to use Particle.function()
    
    You can find me on Github @jakewantulok
    
    Requirements:
        - Claimed Particle Argon
        - Grove shield for Particle Argon (with the argon in place)
        - Grove Starter Kit for Particle Mesh
            - Button ~ plugged into grove shield (D2)
            - Buzzer ~ plugged into grove shield (D4)
        - USB Cable & Internet! (Duh)

    Note! Right now this is written assuming the button is plugged in.
    When unplugged, you will soon hear a loop of of all the tunes.
    
    I highly recommend commenting out:
        - #define BTN D2
        - pinMode(BTN, INPUT);
        - Everything inside void loop()
    
*/

////////////////// 🎹 //////////////////

// Scale = 440hz * 4
// lowercase = natural, uppercase = sharp
int a = 1760;
int A = 1864.66;
int b = 1975.54;
int c = 2093;
int C = 2217.46;
int d =  2349.32;
int D = 2489.02;
int e =  2637.02;
int f =  2793.82;
int F = 2959.96;
int g =  3135.96;
int G = 3322.44;

////////////////// SETLIST //////////////////

/*
    
    Tune 0 = "Pokémon"
    Tune 1 = "Kim Possible"
    Tune 2 = "Power Rangers"
    Tune 3 = "Sesame Street"
    Tune 4 = "Smooth Criminal"
    Tune 5 = "Star Wars"
    Tune 6 = "Indiana Jones"
    Tune 7 = "Mario Bros"
    Tune 8 = "Legend of Zelda"
    Tune 9 = "Example Melody" (with comments)
    
*/

// Will play through each tune each time the button is pressed ~ will restart to the beginning.
int tune = 0; // default 0

////////////////// SETUP //////////////////

void setup() {
    pinMode(BTN, INPUT);
    pinMode(BZZ, OUTPUT);
    Particle.function("PlayTune", playTune); // No spaces or special characters in the string ~ or else it won' work
}

////////////////// BUTTON LOOP //////////////////

void loop() {
    if (digitalRead(BTN) == HIGH) {
        if (tune == 0) {
            playPokemon();
        } else if (tune == 1) {
            playKimPossible();
        } else if (tune == 2) {
            playPowerRangers();
        } else if (tune == 3) {
            playSesameStreet();
        } else if (tune == 4) {
            playSmoothCriminal();
        } else if (tune == 5) {
            playStarWars();
        } else if (tune == 6) {
            playIndianaJones();
        } else if (tune == 7) {
            playMarioBros();
        } else if (tune == 8) {
            playLegendOfZelda();
        } else {
            playExampleMelody();
        }
    }
}

////////////////// PARTICLE.FUNCTION //////////////////

int playTune(String songTitle) {
    if (songTitle == "pokemon" || songTitle == "Pokemon" || songTitle == "pokémon" || songTitle == "Pokémon" || songTitle == "Pocket Monsters" || songTitle == "0") {
        playPokemon();
    } else if (songTitle == "kimpossible" || songTitle == "Kimpossible" || songTitle == "impossible" || songTitle == "kim possible" || songTitle == "Kim Possible" || songTitle == "1") {
        playKimPossible();
    } else if (songTitle == "Power Rangers" || songTitle == "powerrangers" || songTitle == "power rangers" || songTitle == "mighty morphin time" ||songTitle == "2") {
        playPowerRangers();
    } else if (songTitle == "sesame street" || songTitle == "Sesame Street" || songTitle == "Sesame St" || songTitle == "123 Sesame Street" || songTitle == "3") {
        playSesameStreet();
    } else if (songTitle == "MJ" || songTitle == "Michael Jackson" || songTitle == "Smooth Criminal" || songTitle == "smooth sriminal" || songTitle == "4") {
        playSmoothCriminal();
    } else if (songTitle == "Star Wars" || songTitle == "star wars" || songTitle == "starwars" || songTitle == "pew pew" || songTitle == "5") {
        playStarWars();
    } else if (songTitle == "Indiana Jones" || songTitle == "i hate snakes" || songTitle == "Indie" || songTitle == "indiana jones" || songTitle == "6") {
        playIndianaJones();
    } else if (songTitle == "mario" || songTitle == "Mario" || songTitle == "Peach" || songTitle == "Bowser" || songTitle == "7") {
        playMarioBros();
    }  else if (songTitle == "Zelda" || songTitle == "Legend of Zelda" || songTitle == "Link" || songTitle == "Legend Of Zelda" || songTitle == "legend of zelda" || songTitle == "8") {
        playLegendOfZelda();
    } else {
        playExampleMelody();
    }
    return 1;
}

////////////////// TUNES //////////////////

// "PO - KE - MON!"
int playPokemon() {
    
    int pokemon[] =    {d,f,g};
    int pokemonSeq[] = {8,8,8};

    for (int note = 0; note < 3; note++) {
      int duration = 1000/pokemonSeq[note];
      tone(BZZ, pokemon[note], duration);
      delay(duration * 1.30);
    }
    tune++; // next song
}

// "BEE - BOOP, BEEBOOP!"
int playKimPossible() {
    
    int kimpossible[] =    {g,g, 0,A*2,g};
    int kimpossibleSeq[] = {6,6,12, 12,6};

    for (int note = 0; note < 5; note++) {
      int duration = 1000/kimpossibleSeq[note];
      tone(BZZ, kimpossible[note], duration);
      delay(duration * 1.30);
    }
    tune++; // next song
}

// "GO GO - POW ER - RANG - ERS!"
int playPowerRangers() {
    
    int powerRangers[] =    {e,e,d,e,0,g,e};
    int powerRangersSeq[] = {4,4,8,8,8,4,1};

    for (int note = 0; note < 7; note++) {
      int duration = 1000/powerRangersSeq[note];
      tone(BZZ, powerRangers[note], duration);
      delay(duration * 1.30);
    }
    tune++; // next song
}

// "LET ME TELL YOU HOW TO GET, HOW TO GET TO SESAME STREET"
int playSesameStreet() {
    
    int sesameStreet[] =    {A*2,c,d,c,A*2,g,f,f,g,G,g,f,g,A*2,A*2};
    int sesameStreetSeq[] = {  8,8,4,4,  4,8,4,8,8,4,4,8,8,  8,  4};
    
    for (int note = 0; note < 15; note++) {
      int duration = 1000/sesameStreetSeq[note];
      tone(BZZ, sesameStreet[note], duration);
      delay(duration * 1.30);
    }
    tune++; // next song
}

// Intro
int playSmoothCriminal() {
    
    int smoothCriminal[] =    { a, a, a, a, g, a, b, b, a, b, c, c, c, c, b, g/2};
    int smoothCriminalSeq[] = {12,12,12,12,12,12,12, 3,12,12,12, 3,12,12,12,   3};
    
    for (int note = 0; note < 16; note++) {
      int duration = 1000/smoothCriminalSeq[note];
      tone(BZZ, smoothCriminal[note], duration);
      delay(duration * 1.30);
    }
    tune++; // next song
}

// Just waiting for the movie to start...
int playStarWars() {
    int starWars[] =    {g/2,g/2,g/2,c,g,f,e,d,c*2,g,f,e,d,c*2,g,f,e,f,d};
    int starWarsSeq[] = {  4,  4,  4,1,1,4,4,4,  1,1,4,4,4,  1,1,4,4,4,1};
    
    for (int note = 0; note < 19; note++) {
      int duration = 1000/starWarsSeq[note];
      tone(BZZ, starWars[note], duration);
      delay(duration * 1.30);
    }
    tune++; // next song
}

// "I HATE SNAKES"
int playIndianaJones() {
    
    int indianaJones[] =    {d,D,f,A*2,d,f,D};
    int indianaJonesSeq[] = {4,8,8,  1,4,8,1};
    
    for (int note = 0; note < 7; note++) {
      int duration = 1000/indianaJonesSeq[note];
      tone(BZZ, indianaJones[note], duration);
      delay(duration * 1.30);
    }
    tune++; // next song
}

// You know this one
int playMarioBros() {
    int mario[] =    {e,e,e,d,e,g,0,g/2};
    int marioSeq[] = {8,8,4,8,4,4,4,  4};
    
    for (int note = 0; note < 8; note++) {
      int duration = 1000/marioSeq[note];
      tone(BZZ, mario[note], duration);
      delay(duration * 1.30);
    }
    tune++; // next song
}

// No, the green dude is NOT Zelda
int playLegendOfZelda() {
    
    int zelda[] =    { a,0,e/2, 0,g/2, a, b, c, d, e, e, d, e, f, g,a*2,A*2,A*2,A*2,a*2,0,g,0,a*2,f,e}; 
    int zeldaSeq[] = {12,6,  6,12, 12,12,12,12,12,12, 1,12,12,12,12, 12, 12,  1,  8,  8,8,8,0,  4,8,4};
    
    for (int note = 0; note < 25; note++) {
      int duration = 1000/zeldaSeq[note];
      tone(BZZ, zelda[note], duration);
      delay(duration * 1.30);
    }
    tune++; // next song
}

// Example Melody
int playExampleMelody() {
    // Make sure both arrays are equal in size
    int melody[] = {e,f,c,d,e,0,d,e}; // you can also go up or down an octave: a*2 or a/2 
    int melodySeq[] = {8,16,16,8,8,8,8,8};
    
    // Write `note < the length of array` (Not happy with `sizeof()` ~ expect weird behavior)
    for (int note = 0; note < 8; note++) {
      int duration = 1000/melodySeq[note];
      tone(BZZ, melody[note], duration); // Up or down an octave `melody[note]*2` or `melody[note]/2`
      delay(duration * 1.30);
    }
    tune = 0; // restarts SETLIST
}

/*

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

*/
