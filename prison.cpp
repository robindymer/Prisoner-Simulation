#include <iostream>
#include <string>
#include <cstdlib> // For rand()
#include <time.h> // For random seed
using namespace std;

// Function declarations
int randint(int num);
void swap(int *a, int *b);

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
    void shuffleNumbers();
    int getNumber(int i);
    bool openBox();
};

/* Main program */
int main()
{
  int bufSize = 10;
  // Create a room with 100 boxes
  // Each "box" (element in the array) has a unique number ranging
  // from 1-100
  Room room = Room(bufSize);

  // Test
  // room.print();

  // Try to find number by following the loop
  // Run the simulation n times
  int n = 100;
  int failed = 0;

  for (int _ = 0; _ < n; _++)
  {

    room.shuffleNumbers();
    
    for (int i = 1; i <= bufSize; i++)
    {
      int attempts = 0;
      int current = i;
      bool survived = false;

      while (attempts < bufSize / 2)
      {
        int next = room.getNumber(current-1);
        attempts++;

        if (next == i)
        {
          // cout << "Number found at attempt: " << attempts << endl;
          survived = true;
          break;
        }
        
        current = next;
      }

      if (!survived)
      {
        cout << "Number not found!" << endl;
        failed++;
        break;
      }
    }

  }
  cout << "Rate of success: " << failed;
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

int Room::getNumber(int i)
{
  return boxes[i];
}

bool Room::openBox()
{
  return true;
}

// Make the sequence random
void Room::shuffleNumbers()
{
  // Set the seed
  srand(time(NULL));

  // Swap one by one, starting with the last element
  for (int i = bufSize - 1; i > 0; i--)
  {
    // Random index from 0 to i
    int j = rand() % (i + 1);
    swap(&boxes[i], &boxes[j]);
  }
}

// Swap two integers
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}