/*
Ricardo Leidenz
Projectt: Rocket Height.
Summary: Program calculates the height of a rocket every second that passes by, given an initial velocity.
*/
#include <iostream>

int main() 
{
   int rocketHeight = 0; 
   int initialVelocity = 0;
   int timeSinceLaunch = 0; 
   bool done = false;
   std :: cout << "Input velocity(in kms/h): ";
   std :: cin >> initialVelocity;
   
   while (not done)
   {
      rocketHeight = (initialVelocity * timeSinceLaunch) - (5 * (timeSinceLaunch * timeSinceLaunch));
      if( rocketHeight >= 0){
         std :: cout << timeSinceLaunch << " " << rocketHeight << std :: endl;
         timeSinceLaunch += 1;
      }   
      else 
         done = true;
   }
   return 0;
}
