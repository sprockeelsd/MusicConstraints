/**
 * @file Tonality.cpp
 * @author Sprockeels Damien (damien.sprockeels@uclouvain.be)
 * @brief This class represents a tonality based on a root note and a mode
 * @version 0.1
 * @date 2023-03-08
 *
 */

#include "Tonality.hpp"

/**
 * @brief Construct a new Tonality object. The default values are C and MAJOR_SCALE
 *
 */
Tonality::Tonality() : key(C), mode(MAJOR_SCALE)
{
    tonalityNotes = getAllNotesFromTonality(key, mode);
    scaleDegrees = {unisson, majorSecond, majorThird, perfectFourth, perfectFifth, majorSixth, majorSeventh};
    scaleDegreesChordQualities = {MAJOR_CHORD, MINOR_CHORD, MINOR_CHORD, MAJOR_CHORD, MAJOR_CHORD, MINOR_CHORD, DIMINISHED_CHORD};

    int i = 0;
    for (int deg : scaleDegrees)
    {
        scaleDegreeNotes.insert(make_pair(deg, getAllGivenNote(key + deg)));
        scaleDegreeChords.insert(make_pair(deg, getAllNotesFromChord(key, scaleDegreesChordQualities[i])));
        i += 1;
    }
};
