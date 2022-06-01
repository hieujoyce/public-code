#!/usr/bin/python

import shodan
import os

SHODAN_API_KEY = "ptNfQMuGKFphM8Y7D8unwhhTZJCSlLJ8"
# print(SHODAN_API_KEY)
shodan = shodan.Shodan(SHODAN_API_KEY)

try:
    resultados = shodan.search('nginx')
    print("results :",resultados.items())
except Exception as exception:
    print(str(exception))