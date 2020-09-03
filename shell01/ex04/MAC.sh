#!/bin/sh
ifconfig | grep ether | tr -d "\t" | cut -d ' ' -f 2

