#!/usr/bin/env bash

set -e

python3 -m venv env
. env/bin/activate
pip install -r requirements.txt --disable-pip-version-check
python setup.py build_ext --inplace
python main.py
