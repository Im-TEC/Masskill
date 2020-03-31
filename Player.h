/*
*     Made By TEC1204
*     Discord: TEC1204#8384
*     Date: 3/30/20
*     Time: 5:43
*     Game: Forward Assault
*     Device: IOS
*/


class Player{
public:
  static int get_Team(void *Player);

  static float get_Health(void *Player);

  static bool get_isMine(void *Player);
  static bool get_isLiving(void *Player);
};

int Player::get_Team(void *Player){
  return *(int *)((uint64_t)Player + 0x210);
}

float Player::get_Health(void *Player){
  return *(float *)((uint64_t)Player + 0x1EC);
}

bool Player::get_isMine(void *Player){
  return *(bool *)((uint64_t)Player + 0xCC);
}
bool Player::get_isLiving(void *Player){
  return Player::get_Health(Player) > 1;
}
