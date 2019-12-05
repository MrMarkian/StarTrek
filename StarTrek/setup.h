void HUD();
void UPDATE_ENERGY_LEVELS();
void BOOT_UP();
void DRAW_BORD();
void INIT_BOARD(int difficulty, int x, int y);
int acceptinput(int input);
int move_enterprise(int x, int y);
void fireat();
int CALCULATE_DAMAGE(int weapon, int strength);
void DOCK();
void END_TURN();
void TITLE_SCREEN();
void ClearNRedraw();
void DrawFireAnim(int x,int y, int myX,int  myY, int weapon);
void DrawRangeFinder(int myX, int myY);
void DrawGalaxyMap(int ask);
void DrawDeathAnim(int myX, int myY);
void BuyItems();
void CaptiansLog();
void UpgradeEnterprise();
void DrawWarpAnim();
void GameTime(int input);

HWND hWnd;
HDC hDC;
int unicounter;
int weaponlock;
int docked;
int difficulty;
int fired;
int TotalKlingons;
int gametime;

int damageresult;
int galaxyX = 5, galaxyY = 5;

struct starb
{
	int x;
	int y;
	int torpedo;  //torpedos in stock!
	int torpprise; // torpeods price (missspelled)
	int recharge; //How much energy given to enterprise when docked
	int coil; // If the starbase offers a warp coil upgrade.
};

struct square
{
	int contains; //What the grid contains
	int enemytag;// Cant rememeber what thtis one does.. Should probably check it out!
	int klingons; // Cant rememeber where this is used either..
	//------------------
	int probed;//<<-- only on galaxy to determin if sector has been probed
	int visited; //This is used for galaxy map, to show if that particular area in glaxy array has been visited
	int sbvisited; // Same again but for the starbase

};


struct ship
{
	int energy;
	int hull;
	int shields;
	int phaser;
	int impulse;
    int energymax;
	int hullmax;
	int shieldsmax;
	int phasermax;
	int impulsemax;
	int x; //Location in Galaxy for possible use in location logic..
	int y; //


	int photons;
	int probes;
	int warpcoil;
	int shipclass;
	int experience;

	//statistics
	int tfired;  //Total Traveled
	int glTraveled; //Glaxys Traveled
	int kills; // Kills Obv
	int score;	//Ovb
	int damagecaused; //total Damage
	int sbvisited; // Star Bases Visited
	int damagetaken;  //Obv Damage Taken
};


struct square gameboard[10][10];
struct ship klingon[3000];
struct ship enterprise[1];
struct starb starbase[1];
struct square galaxy[10][10];

char *SquareContains[] =
{
	"NOTHING",
	"ENTERPRISE",
	"KLINGON",
	"PLANET",
};

	char *piecetype[]=
        {
			"ú",
			"E",
			"K",
			"",
            "õ",
        };
