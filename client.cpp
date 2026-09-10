#include "ft_irc.hpp"

int	main()
{
	Client	sock("8081", "troll");
	sock.establishConnection();
	return (0);
}
