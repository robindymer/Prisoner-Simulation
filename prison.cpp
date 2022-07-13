#include <iostream>
#include <string>
#include <cstdlib> // For rand()
#include <time.h> // For random seed
using namespace std;

// Function declarations
int randint(int num);

/* Describes the room where the prisoner enters */
class Room
{
  private:
    int bufSize;
    int *boxes;
  public:
    Room();
    Room(int bufSize);
    ~Room();
    void print();
    void generateNumbers();
    bool openBox();
};

/* Main program */
int main()
{
  int bufSize = 100;
  // Create a room with 100 boxes
  // Each "box" (element in the array) has a unique number ranging
  // from 1-100
  Room room = Room(bufSize);

  // Test
  room.print();
  return 0;
}

/* Member functions */
Room::Room()
{
  bufSize = 0;
  boxes = 0; // Null pointer
}

Room::Room(int bufSize)
  : bufSize(bufSize)
{
  if (bufSize > 0)
  {
    boxes = new int[bufSize];

    // TODO: Call shuffle()
    for (int i = 0; i < bufSize; i++)
      boxes[i] = i + 1;
  } else
    boxes = 0; // Null pointer
}

Room::~Room()
{
  delete[] boxes;
}

void Room::print()
{
  for (int i = 0; i < bufSize; i++)
    cout << "Box contains the number: " << boxes[i] << endl;
}

// Make the sequence random
void shuffleNumbers()
{
  //TODO: Implement
}

bool Room::openBox()
{
    return true;
}
