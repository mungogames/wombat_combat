/////////////////////////////////////////////
/// @brief Player class
///
/// @author Simon J
/// @date 03/15/2012 - 03/18/2012
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
  Player(GameContainer* gc, float posX, float posY, float sizeX, float sizeY);
  
  /// @brief Getter
  Direction getMovingDirection();
  float getJumpSpeed();
  bool isRunning();
  bool isMoving();
  
  /// @brief Setter
  void setJumpSpeed(float jumpSpeed);
  void move(Direction direction);
  void stopMoving();
  void jump();
  void setRunning(bool running);
  
  /// @brief Updates the player
  void update();
  
  /// @brief Renders the object
  void render();
};



#endif
