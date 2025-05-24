from setuptools import find_packages
from setuptools import setup

setup(
    name='goat_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('goat_interfaces', 'goat_interfaces.*')),
)
