## Bowling management system [![Build Status](https://travis-ci.org/CodersSchool777/bowling.svg?branch=master)](https://travis-ci.org/CodersSchool777/bowling) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/da2461c4b12b49c6a105fe55b47c7c98)](https://www.codacy.com/app/CodersSchool777/bowling?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=CodersSchool777/bowling&amp;utm_campaign=Badge_Grade) [![codecov](https://codecov.io/gh/CodersSchool777/bowling/branch/master/graph/badge.svg)](https://codecov.io/gh/CodersSchool777/bowling) [![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

The goal of the project is to manage bowling competitions

###  Used tools:
- C++ version: C++11
- Build system: CMake
- C++ compiler: g++
- Libraries: STL and Boost
- Code coverage: yes

### Project assumptions:
- counting partial points: 3-|X|4/|3
- counting total points: X|7/|9-|X|-8|8/|-6|X|X|X||81
- validation of input data
- data is extracted from many files from one directory
- displaying players results on the screen divided into tracks (with the status of the game) and writing them to one file

### Examples:

X indicates a strike
<br>/ indicates a spare
<br>- indicates a miss
<br>| indicates a frame boundary
<br>The characters after the || indicate bonus balls

X|X|X|X|X|X|X|X|X|X||XX
<br>Ten strikes on the first ball of all ten frames.
<br>Two bonus balls, both strikes.
<br>Score for each frame == 10 + score for next two 
<br>balls == 10 + 10 + 10 == 30
<br>Total score == 10 frames x 30 == 300

9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||
<br>Nine pins hit on the first ball of all ten frames.
<br>Second ball of each frame misses last remaining pin.
<br>No bonus balls.
<br>Score for each frame == 9
<br>Total score == 10 frames x 9 == 90

5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5
<br>Five pins on the first ball of all ten frames.
<br>Second ball of each frame hits all five remaining
<br>pins, a spare.
<br>One bonus ball, hits five pins.
<br>Score for each frame == 10 + score for next one
<br>ball == 10 + 5 == 15
<br>Total score == 10 frames x 15 == 150
