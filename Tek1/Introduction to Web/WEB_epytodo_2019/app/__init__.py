# -*- coding: utf-8 -*-
import os
import locale
from flask import *
from flask import Flask, request, render_template, flash, redirect, url_for, session, logging
import pymysql as sql
from wtforms import Form, StringField, TextAreaField, PasswordField, validators
from passlib.hash import sha256_crypt
from functools import wraps
from app.controllers import *

app = Flask(__name__)
app.config.from_object('config')

def get_application():
    return app