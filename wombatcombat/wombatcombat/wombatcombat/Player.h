/////////////////////////////////////////////
/// @brief Player class
///
/// @author Simon
/// @version 0.2
/// @date 2012
///
/// @copyright Mungo Games
/////////////////////////////////////////////

#ifndef wombatcombat_Player_h
#define wombatcombat_Player_h

#include "enums.h"
#include "GameContainer.h"
#include "Creature.h"
#include "CreatureData.h"
#include "Gun.h"

using namespace std;

class Player: public Creature 
{
  //Parameters 
private:  
  GameContainer* gc;
  
  Gun* weapon; ///< Weapon of the player (to this point its a bow)
  
  float movingSpeed;
  float runningSpeed;
  Direction movingDirection;
  
  float jumpSpeed;
  
  bool running;
  
public:
  
  /////////////////////////////////////////////
  /// @brief Constructor
  //
  /// @param gc             Reference to the GameContainer
  /// @param posX,feetPosY  Position of the player, Y-pos describes lower edge of the hitbox
  /// @param sizex,sizeY    Size of the hitbox in two directions
  /////////////////////////////////////////////
  
  Player(GameContainer* gc, float posX, float posY, float sizeX, float sizeY);
  
  // Getter
  Direction getMovingDirection();
  float getJumpSpeed();
  bool isRunning();
  bool isMoving();
  
  //Setter
  void setJumpSpeed(float jumpSpeed);
  void move(Direction direction);
  void stopMoving();
  void jump();
  void setRunning(bool running);
  
  //Update and render methods
  void update();
  void render();
};



#endif
