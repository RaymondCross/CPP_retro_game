#include "Game.Class.hpp"

Game::Game() : _total_enemies(0), _score(0), _state(0), _tick(0)
{
	this->_window = new Window();
	while (this->_window)
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
		// this->_enemies = rhs._enemies;
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
	attron(COLOR_PAIR(1));
	mvwaddstr(WIN, WIN_HEIGHT / 2 - 3, WIN_WIDTH / 2 - 10, "<SAD SPACE INVADERS>");
	mvwaddstr(WIN, WIN_HEIGHT / 2, WIN_WIDTH / 2 - 13, "Press 'SPACEBAR' to start");
	attroff(COLOR_PAIR(1));
	wrefresh(WIN);

	char	in;

	while (this->_window)
	{
		in = wgetch(WIN);
		if (in == ' ')
		{
			this->setState(1);
			this->_player = new Player;
			this->_player->setY(WIN_HEIGHT / 2);
			this->_player->setX(10);
			werase(WIN);
			break ;
		}
	}
}

void	Game::gameLoop()
{
	nodelay(WIN, true);
	char	in;

	if (!this->_player->getLives())
	{
		this->setState(2);
		return ;
	}
	in = std::tolower(wgetch(WIN));
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

	case 27:// ESC key
		this->setState(3);
		break;

	case 'k':
		this->setState(2);
		break;

	case ' ':
		this->_player->fire();
		break;

	default:
		break;
	}

	if (this->_tick % 50 == 0)
	{
		// this->spawnEnemy();
	}
	if (this->_tick % 25 == 0)
	{
		// this->enemyShoot();
	}

	// this->detectCollision();

	werase(WIN);
	this->drawHUD();
	this->drawEntities();
}

void	Game::drawHUD()
{
	std::string	s;

	attron(COLOR_PAIR(1));
	mvwaddstr(WIN, WIN_HEIGHT - 2, 2, "LIVES: ");// draw lives
	s = std::to_string(this->_player->getLives());
	mvwaddstr(WIN, WIN_HEIGHT - 2, 9, s.c_str());
	mvwaddstr(WIN, WIN_HEIGHT - 2, 11, "SCORE: ");// draw score
	s =  std::to_string(this->_score);
	mvwaddstr(WIN, WIN_HEIGHT - 2, 18, s.c_str());
	attroff(COLOR_PAIR(1));
}

void	Game::drawEntities()
{
	this->drawPlayer();
	// this->drawEnemies();
	// this->drawProjectiles();
	// this->drawAsteroids();
}

void	Game::drawPlayer()
{
	attron(COLOR_PAIR(2));
	mvwaddch(WIN, PLAYER_Y, PLAYER_X, PLAYER_CHAR);// draw player
	attroff(COLOR_PAIR(2));
}

void	Game::deathScreen()
{
	delete this->_player;
	// this->_enemies = NULL;
	nodelay(WIN, false);

	char	in;

	// display death screen

	werase(WIN);
	attron(COLOR_PAIR(1));
	mvwprintw(WIN, WIN_HEIGHT / 2 - 3, WIN_WIDTH / 2 - 10, "<YOU DIED>");
	mvwprintw(WIN, WIN_HEIGHT / 2, WIN_WIDTH / 2 - 13, "Press 'R' to restart");
	mvwprintw(WIN, WIN_HEIGHT / 2 + 3, WIN_WIDTH / 2 - 13, "Press 'Q' to quit");
	attroff(COLOR_PAIR(1));
	wrefresh(WIN);

	while (this->_window)
	{
		in = std::tolower(wgetch(WIN));
		if (in == 'r')
		{
			this->restart();
			this->setState(1);
			break ;
		}
		else if (in == 'q')
		{
			werase(WIN);
			delete this->_window;
			std::exit(1);
			// this->exit();
		}
	}
}

void	Game::helpMenu()
{
	nodelay(WIN, false);

	char	in;

	// display
	attron(COLOR_PAIR(1));
	mvwprintw(WIN, WIN_HEIGHT / 2 - 3, WIN_WIDTH / 2 - 10, "<WASD> to move");
	mvwprintw(WIN, WIN_HEIGHT / 2, WIN_WIDTH / 2 - 12, "<SPACEBAR> to shoot");
	mvwprintw(WIN, WIN_HEIGHT / 2 + 3, WIN_WIDTH / 2 - 14, "Press any key to resume");
	attroff(COLOR_PAIR(1));
	while (this->_window)
	{
		in = std::tolower(wgetch(WIN));
		if (in)
			break;
	}
	this->setState(1);
}

void	Game::restart()
{
	this->_player = new Player;
	this->_player->setY(WIN_HEIGHT / 2);
	this->_player->setX(10);
	this->_total_enemies = 0;
	this->_score = 0;
	this->_tick = 0;
	werase(WIN);
	mvwaddch(WIN, PLAYER_Y, PLAYER_X, PLAYER_CHAR);
}

void	Game::detectCollision()
{

}
