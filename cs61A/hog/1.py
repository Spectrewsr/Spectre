import hog
from dice import six_sided, four_sided, make_test_dice
from ucb import main, trace, interact

from hog import play, always_roll
from dice import make_test_dice
#
dice = make_test_dice(1,2) 
print(hog.extra_turn_strategy(24, 5, cutoff=1, num_rolls=6))
