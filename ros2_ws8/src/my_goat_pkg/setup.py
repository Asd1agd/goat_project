from setuptools import find_packages, setup

package_name = 'my_goat_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'rclpy', 'goat_interfaces'],
    zip_safe=True,
    maintainer='asd',
    maintainer_email='a93054223@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'navigator_server = my_goat_pkg.navigator:main',
            'goat_robo = my_goat_pkg.robot_core_logic:main',

        ],
    },
)
