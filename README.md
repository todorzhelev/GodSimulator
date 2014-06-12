GodSimulator
============

This program simulates a God, which has control over planets and entities on the planets.

Entities can do different actions, based on their type.
At any moment the player can monitor the current population at all the planets, 
can destroy the population at certain planet,
create random planet or add manually entities to a planet.

Technical implementation
============
Some c++11 features are used in the program, like lambda functions, algorithms, bind, smart pointers, etc.

The program uses one additional thread - for the input from the player.

At any moment, while the program waits for the player's input, the simulator is running and the entities are 
performing their actions.

The program relies mostly on the random generator, as all the decisions are taken by random and the entities are moving
around by a random amount. Also the names of the entities are chosen by random.(Including the player's name)

Up to 200 000 entities can be supported before the sumilator will start to respond slow on the commands by the player.
The commands are typed by the player and then are parsed.
