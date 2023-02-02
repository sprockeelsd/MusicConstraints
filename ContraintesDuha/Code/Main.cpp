/**
 * @file Main.cpp
 * @author Sprockeels Damien (damien.sprockeels@uclouvain.be)
 * @brief This function creates the problem
 * @version 1.0
 * @date 2023-02-01
 *
 */
#include "Main.h"



/**********************************************
 *                                            *
 * @brief This function creates the problem   *
 *                                            *
 **********************************************/

int main(int argc, char *argv[])
{
    // INPUT
    vector<int> chordRoots = {C,F,B,C};
    vector<vector<int>> chordQualities = {MAJOR_CHORD, MAJOR_CHORD, DIMINISHED_CHORD, MAJOR_CHORD};
    vector<int> chordBass = {C,F,B,C};

    FourVoiceTexture *problem = new FourVoiceTexture(4,C,MAJOR_SCALE, chordRoots, chordQualities, chordBass); // Create the problem

    // Search options
    Gecode::Search::Options opts;
    opts.threads = 0; // As many as possible
    Gecode::Search::TimeStop maxTime(10); // Search for max 1s
    opts.stop = &maxTime;

    // Create the search engine
    DFS<FourVoiceTexture> e(problem, opts);
    delete problem;

    int nbSol = 0;
    while (FourVoiceTexture *s = e.next())
    {
        std::cout << " Solution " << nbSol + 1 << " : " << std::endl;
        s->print();
        std::cout << std::endl;
        delete s;
        ++nbSol;
    }

    std::cout << "Finished. Number of solutions found: " << nbSol << std::endl;

    return 0;
}