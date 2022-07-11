#include <iostream>
#include <string>

/* Describes the room where the prisoner enters */
class Room
{
  private:
    int boxes;
  public:
    Room();
    ~Room();
    bool openBox();
};

/* Main program */
int main()
{
  return 0;
}

/* Member functions */
Room::Room()
{
  boxes = 0;
}

bool Room::openBox()
{
    return true;
}