/*
*     Made By TEC1204
*     Discord: TEC1204#8384
*     Date: 3/30/20
*     Time: 5:59
*     Game: Forward Assault
*     Device: IOS
*/
#import "Player.h"
#import "Vector3.h"

/*Here we get the right offset*/
uint64_t getRightOffset(uint64_t offset){
	return _dyld_get_image_vmaddr_slide(0) + offset;
}


 void *(*Component$$get_transform)(void *component) = (void *(*)(void *))getRightOffset(0x1023721E0);
 void (*Transform$$get_position_Injected)(void *Transform, Vector3 *outPosition) = (void (*)(void *, Vector3 *))getRightOffset(0x10239DA4C);
 void (*Transform$$set_position_Injected)(void *Transform, Vector3 outPosition) = (void (*)(void *, Vector3))getRightOffset(0x10239DAF4);

/*Here we get the position the easier way*/
Vector3 getPosition(void *component){
  /* Varible to get the position*/
  Vector3 out;
  /*get the transform of the object*/
  void *transform = Component$$get_transform(component);
  /* Set the out varible to the position of the object*/
  Transform$$get_position_Injected(transform, &out);
  /* Return the verible out*/
  return out;
}

/*Here we set the position the easier way*/
void setPosition(void *component, Vector3 newPosition){
  /*get the transform of the object*/
  void *transform = Component$$get_transform(component);
  /* set the object position to the new position*/
  Transform$$set_position_Injected(transform, newPosition);
}


void DoMassKill(std::vector<void*> enemyPlayers){
	for(int i = 0; i < enemyPlayers.size(); i++){
                if(myPlayer && Player::get_isLiving(player) && Player::get_isLiving(myPlayer) && Player::get_Team(myPlayer) != Player::get_Team(player)){
                Vector3 myPosition = getPosition(myPlayer);
                setPosition(enemyPlayers[i], Vector3(myPosition.x, myPosition.y, myPosition.z + 1));
		}
	}
}
 

