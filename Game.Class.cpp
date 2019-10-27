#include "Game.Class.hpp"

Game::Game() : _enemies(NULL), _total_enemies(0), _score(0), _state(0), _tick(0)
{
	this->_window = new Window();
	_total_enemies = 0;//---------------------------
	while (1)
		this->displayState();
}

Game::Game(const Game &src)
{
	*this = src;
}

Game::~Game()
{
}

Game	&Game::operator=(const Game &rhs)
{
	if (this != &rhs)
	{
		this->_window = rhs._window;
		this->_enemies = rhs._enemies;
		this->_score = rhs._score;
		this->_state = rhs._state;
		this->_tick = rhs._tick;
	}
	return *this;
}

void	Game::setState(int state)
{
	this->_state = state;
}

typedef struct	s_dispatch
{
	void	(Game::*f)();
}				t_dispatch;

void	Game::displayState()
{
	t_dispatch states[4] =
	{
		{&Game::mainMenu},
		{&Game::gameLoop},
		{&Game::deathScreen},
		{&Game::helpMenu}
	};

	(this->*states[this->_state].f)();
	usleep(10000);
	wrefresh(WIN);
	this->_tick++;
}

void	Game::mainMenu()
{
	mvwprintw(WIN, WIN_HEIGHT / 2 - 15, WIN_WIDTH / 2 - 15, "GAME TITLE HERE");
	mvwprintw(WIN, WIN_HEIGHT / 2, WIN_WIDTH / 2 - 19, "Press =SPACEBAR= to start");

	char	in;

	while (1)
	{
		wrefresh(WIN);
		in = getch();
		if (in == ' ')
		{
			this->setState(1);
			this->_player = new Player;
			this->_player->setY(WIN_HEIGHT / 2);
			this->_player->setX(10);
			nodelay(WIN, true);
			werase(WIN);
			mvwaddch(WIN, PLAYER_Y, PLAYER_X, PLAYER_CHAR);
			break ;
		}
	}
}

void	Game::gameLoop()
{
	char	in;

	if (!this->_player->getLives())
	{
		this->setState(2);
		return ;
	}
	in = getch();
	switch (in)
	{
	case 'w':
		this->_player->moveup(WIN_HEIGHT);
		break;

	case 'a':
		this->_player->moveleft(WIN_WIDTH);
		break;

	case 'd':
		this->_player->moveright(WIN_WIDTH);
		break;

	case 's':
		this->_player->movedown(WIN_HEIGHT);
		break;

	default:
		break;
	}
	werase(WIN);
	mvwaddch(WIN, PLAYER_Y, PLAYER_X, PLAYER_CHAR);
	// mvwaddch(WIN, );//HUD (SCORE, LIVES, ETC.)
	wrefresh(WIN);
}

void	Game::deathScreen()
{
	nodelay(WIN, false);
	//
	nodelay(WIN, true);
}

void	Game::helpMenu()
{
	nodelay(WIN, false);
	//
	nodelay(WIN, true);
}
