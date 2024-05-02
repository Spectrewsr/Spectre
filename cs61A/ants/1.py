from ants import *
beehive, layout = Hive(AssaultPlan()), dry_layout
dimensions = (1, 9)
gamestate = GameState(None, beehive, ant_types(), layout, dimensions)
# >>> #
# >>> # Testing Long/ShortThrower parameters
ant = LongThrower()
out_of_range = Bee(2)
#gamestate.places["tunnel_0_0"].add_insect(ant)
gamestate.places["tunnel_0_4"].add_insect(out_of_range)
ant.action(gamestate)
print(out_of_range.armor)
print(ShortThrower.food_cost)