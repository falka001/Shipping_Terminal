# Shipping_Terminal

This project is a Shipping Terminal simulation interacting with a railroad switching yard.
The user is able to enter the desired number of ships that will be entering the shipping terminal, and how many containers it will have, each ship can have a different number of containers.
Each container will have a specific ID and destination code, where the destination code is generated at random between the values of 100 and 999.

The simulation is designed to unload the containers from the ship to 9 cranes, then from the cranes to the switching track, then to the shipping track. The cranes could only take one container at a time, so 9 containers will be removed from the ship and moved to the switching track.

The rules:
   - The switching track is only allowed to store 40 containers, if it is full, then the containers are moved to the shipping track.
   - The shipping track is only allowed to store 100 containers. If it is full, then the containers are deleted, as if they have been shipped.
      - Shipping track #1: stores containers with a destination code ranging from 100-199
      - Shipping track #2: stores containers with a destination code ranging from 300-399
      - Shipping track #3: stores containers with a destination code ranging from 500-599
      - Shipping track #5: stores containers with a destination code ranging from 900-999
   - The siding is only allowed to store containers that do not meet the destination code of the shipping track, such as containers with destination code 283, 432, ... etc.

Data Structures:
   - ships with containers: 4-dimensional vector
   - cranes: vector
   - Switching track: queue
   - Shipping track: queue
   - Siding: stack
