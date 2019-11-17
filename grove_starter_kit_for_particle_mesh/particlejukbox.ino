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
        - Grove Starter Kit for Particle Mesh:
            - Grove shield for Particle Argon (with the argon in place)
            - Button ~ plugged into grove shield (D2)
            - Buzzer ~ plugged into grove shield (D4)
        - USB Cable & Internet! (Duh)

    Note! Right now this is written assuming the button is plugged in.
    When unplugged, you will soon hear each tune play in a continuous loop.
    
    I highly recommend commenting out the following before unplugging your button:
        - #define BTN D2
        - pinMode(BTN, INPUT);
        - Everything inside the void loop()
*/

////////////////// 🎹 //////////////////

// Scale = 440hz * 4
// lowercase = regular, uppercase = sharp
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

int tune = 0; // default tune for first press

// "PO - KE - MON!"
int pokemon[] =    {d,f,g};
int pokemonSeq[] = {8,8,8};

// "Call me, beep me, if you wanna reach me..."
int kimPossible[] =    {g,g, 0,A*2,g};
int kimPossibleSeq[] = {6,6,12, 12,6};

// It's mighty morphin time!
int pwrRangers[] =    {e,e,d,e,0,g,e};
int pwrRangersSeq[] = {4,4,8,8,8,4,1};

// "LET ME TELL YOU HOW TO GET, HOW TO GET TO SESAME STREET"
int sesameStreet[] =    {A*2,c,d,c,A*2,g,f,f,g,G,g,f,g,A*2,A*2};
int sesameStreetSeq[] = {  8,8,4,4,  4,8,4,8,8,4,4,8,8,  8,  4};

// No, this was NOT written by Alien Antfarm
int smoothCriminal[] =    { a, a, a, a, g, a, b, b, a, b, c, c, c, c, b, g/2};
int smoothCriminalSeq[] = {12,12,12,12,12,12,12, 3,12,12,12, 3,12,12,12,   3};

// Just waiting for the movie to start...
int starWars[] =    {g/2,g/2,g/2,c,g,f,e,d,c*2,g,f,e,d,c*2,g,f,e,f,d};
int starWarsSeq[] = {  4,  4,  4,1,1,4,4,4,  1,1,4,4,4,  1,1,4,4,4,1};

// "I HATE SNAKES"
int indianaJones[] =    {d,D,f,A*2,d,f,D};
int indianaJonesSeq[] = {4,8,8,  1,4,8,1};

// We all know this one
int mario[] =    {e,e,e,d,e,g,0,g/2};
int marioSeq[] = {8,8,4,8,4,4,4,  4};

// No, the green dude is NOT Zelda
int legendOfZelda[] =    { a,e/2, 0,g/2, a, b, c, d, e, e, d, e, f, g,a*2,A*2,A*2,A*2,a*2,0,g,0,a*2,f,e}; 
int legendOfZeldaSeq[] = { 6,  3,12, 12,12,12,12,12,12, 1,12,12,12,12, 12, 12,  1,  8,  8,8,8,0,  4,8,4};

// I don't know how else to knock apparently
int doorKnock[] =    {e, f, c,d,e,0,d,e};
int doorKnockSeq[] = {8,16,16,8,8,8,8,8};

////////////////// JUKEBOX //////////////////

int jukebox(int melody [], int melodySeq [], int size) {
    
    for (int note = 0; note < size; note++) {
      int duration = 1000/melodySeq[note];
      tone(BZZ, melody[note], duration);
      delay(duration * 1.30);
    }
    tune++; // next tune
}

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
            jukebox(pokemon, pokemonSeq, 3);
        } else if (tune == 1) {
            jukebox(kimPossible, kimPossibleSeq, 5);
        } else if (tune == 2) {
            jukebox(pwrRangers, pwrRangersSeq, 7);
        } else if (tune == 3) {
            jukebox(sesameStreet, sesameStreetSeq, 15);
        } else if (tune == 4) {
            jukebox(smoothCriminal, smoothCriminalSeq, 16);
        } else if (tune == 5) {
            jukebox(starWars, starWarsSeq, 19);
        } else if (tune == 6) {
            jukebox(indianaJones, indianaJones, 7);
        } else if (tune == 7) {
            jukebox(mario, marioSeq, 8);
        } else if (tune == 8) {
            jukebox(legendOfZelda, legendOfZelda, 25);
        } else {
            jukebox(doorKnock, doorKnockSeq, 8);
            tune = 0; // resets to the first tune
        }
    }
}

////////////////// PARTICLE.FUNCTION //////////////////

int playTune(String cmd) {
    if (cmd == "pokemon" || cmd == "Pokemon" || cmd == "pokémon" || cmd == "Pokémon" || cmd == "Pocket Monsters" || cmd == "0") {
        jukebox(pokemon, pokemonSeq, 3);
    } else if (cmd == "kimpossible" || cmd == "Kimpossible" || cmd == "impossible" || cmd == "kim possible" || cmd == "Kim Possible" || cmd == "1") {
        jukebox(kimPossible, kimPossibleSeq, 5);
    } else if (cmd == "Power Rangers" || cmd == "powerrangers" || cmd == "power rangers" || cmd == "mighty morphin time" ||cmd == "2") {
        jukebox(pwrRangers, pwrRangersSeq, 7);
    } else if (cmd == "sesame street" || cmd == "Sesame Street" || cmd == "Sesame St" || cmd == "123 Sesame Street" || cmd == "3") {
        jukebox(sesameStreet, sesameStreetSeq, 15);
    } else if (cmd == "MJ" || cmd == "Michael Jackson" || cmd == "Smooth Criminal" || cmd == "smooth sriminal" || cmd == "4") {
        jukebox(smoothCriminal, smoothCriminalSeq, 16);
    } else if (cmd == "Star Wars" || cmd == "star wars" || cmd == "starwars" || cmd == "pew pew" || cmd == "5") {
        jukebox(starWars, starWarsSeq, 19);
    } else if (cmd == "Indiana Jones" || cmd == "i hate snakes" || cmd == "Indie" || cmd == "indiana jones" || cmd == "6") {
        jukebox(indianaJones, indianaJonesSeq, 7);
    } else if (cmd == "mario" || cmd == "Mario" || cmd == "Peach" || cmd == "Bowser" || cmd == "7") {
        jukebox(mario, marioSeq, 8);
    } else if (cmd == "Zelda" || cmd == "Legend of Zelda" || cmd == "Link" || cmd == "triforce" || cmd == "legend of zelda" || cmd == "8") {
        jukebox(legendOfZelda, legendOfZeldaSeq, 25);
    } else {
        jukebox(doorKnock, doorKnockSeq, 8);
        tune = 0; // resets to the first tune
    }
    return 1;
}