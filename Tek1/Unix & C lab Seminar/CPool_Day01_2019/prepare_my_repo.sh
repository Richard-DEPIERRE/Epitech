#!/usr/bin/bash
blih -u richard.habimana@epitech.eu repository create $1
blih -u richard.habimana@epitech.eu repository setacl $1 ramassage-tek r
blih -u richard.habimana@epitech.eu repository getacl $1
