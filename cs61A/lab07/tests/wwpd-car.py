test = {
  'name': 'Car',
  'points': 0,
  'suites': [
    {
      'cases': [
        {
          'code': r"""
          >>> from car import *
          >>> deneros_car = Car('Tesla', 'Model S')
          >>> deneros_car.model
          'Model S'
          >>> deneros_car.gas = 10
          >>> deneros_car.drive()
          'Tesla Model S goes vroom!'
          >>> deneros_car.drive()
          'Cannot drive!'
          >>> deneros_car.fill_gas()
          'Gas level: 20'
          >>> deneros_car.gas
          20
          >>> Car.gas
          30
          """,
          'hidden': False,
          'locked': False
        },
        {
          'code': r"""
          >>> from car import *
          >>> deneros_car = Car('Tesla', 'Model S')
          >>> deneros_car.wheels = 2
          >>> deneros_car.wheels
          2
          >>> Car.num_wheels
          4
          >>> deneros_car.drive() # Type Error if an error occurs and Nothing if nothing is displayed
          'Cannot drive!'
          >>> Car.drive() # Type Error if an error occurs and Nothing if nothing is displayed
          795bceccbca635277a3bbfa64bc9dba0
          # locked
          >>> Car.drive(deneros_car) # Type Error if an error occurs and Nothing if nothing is displayed
          ed7e31d39fdaefb22a23971c5b0eb43d
          # locked
          """,
          'hidden': False,
          'locked': True
        },
        {
          'code': r"""
          >>> from car import *
          >>> deneros_car = MonsterTruck('Monster', 'Batmobile')
          >>> deneros_car.drive() # Type Error if an error occurs and Nothing if nothing is displayed
          beba7598767b3ddfeb4b0163408184fa
          8a7be733d5923219ef98f4d3a98c169c
          # locked
          >>> Car.drive(deneros_car) # Type Error if an error occurs and Nothing if nothing is displayed
          8a7be733d5923219ef98f4d3a98c169c
          # locked
          >>> MonsterTruck.drive(deneros_car) # Type Error if an error occurs and Nothing if nothing is displayed
          beba7598767b3ddfeb4b0163408184fa
          8a7be733d5923219ef98f4d3a98c169c
          # locked
          >>> Car.rev(deneros_car) # Type Error if an error occurs and Nothing if nothing is displayed
          795bceccbca635277a3bbfa64bc9dba0
          # locked
          """,
          'hidden': False,
          'locked': True
        }
      ],
      'scored': False,
      'type': 'wwpp'
    }
  ]
}
