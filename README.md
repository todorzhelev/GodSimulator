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
performing their actions. The main logic is happening in the Update method in the Game class, which consist of :<br />
1.Entities, which have energy below zero are deleted <br />
2.Entities, which were born in the previous iteration of the loop are added to the planets population <br />
3.All the entities on all planets move by a random amount <br />
4.All the entities are sorted by their distance to (0,0,0) <br />
5.Each two consecutive entities are tested if they are close enough. If they are, they perform random action together or alone <br />

Currently supported actions by the entities are to attack other entity or to create new entity.
The other actions, which are specific to different entities, are not fully supported(for instance the humans analyse action just changes his current state to Analyzing).

The program relies mostly on the random generator, as all the decisions are taken by random and the entities are moving
around by a random amount. Also the names of the entities are chosen by random.(Including the player's name)

Up to 200 000 entities can be supported before the sumilator will start to respond slow on the commands by the player.
The commands are typed by the player and then are parsed.

Also documentation for the project is generated with Doxygen. It can be seen by opening index.html in the documentation folder.
