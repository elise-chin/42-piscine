#!/bin/sh
git ls-files $(git rev-parse --show-toplevel) -o -i --exclude-standard
