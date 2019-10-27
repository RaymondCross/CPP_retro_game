#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include "GameEntity.Class.hpp"
# include "Player.Class.hpp"
# include "Window.Class.hpp"

# define WIN	this->_window->getWin()
# define WIN_HEIGHT	this->_window->getHeight()
# define WIN_WIDTH	this->_window->getWidth()

# define PLAYER_CHAR	this->_player->getObj()
# define PLAYER_X	this->_player->getX()
# define PLAYER_Y	this->_player->getY()

typedef struct	s_enemies
{
	GameEntity	*entity;
	s_enemies	*next;
}				t_enemies;

// state: 0 = main menu; 1 = game loop; 2 = death screen; 3 = help menu
class Game
{
private:
	Window	*_window;
	Player	*_player;
	t_enemies	*_enemies;//-----------------
	int	_total_enemies;
	int	_score;
	int	_state;
	int	_tick;
public:
	Game();
	Game(const Game &src);
	~Game();

	Game	&operator=(const Game &rhs);

	void	mainMenu();
	void	gameLoop();
	void	deathScreen();
	void	helpMenu();

	// void	spawnEnemy();
	void	displayState();

	void	setState(int state);
};

#endif
