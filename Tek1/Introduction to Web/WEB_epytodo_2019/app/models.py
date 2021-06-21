# -*- coding: utf-8 -*-
from app import *
from flask import *

class Connect():

    def __init__(self):
        self.app = app

    def connect(self):
        conn = sql.connect(host="127.0.0.1",
                        user='root',
                        password="",
                        db="epytodo",
                        cursorclass=sql.cursors.DictCursor)
        return (conn)


class Model():

    def tasks_model(self):
        conn = Connect().connect()
        cur = conn.cursor()
        result = cur.execute("SELECT * FROM task")
        tasks = cur.fetchall()
        cur.close()
        return (tasks)

    def task_model(self, id):
        conn = Connect().connect()
        cur = conn.cursor()
        result = cur.execute("SELECT * FROM task WHERE task_id = %s", id)
        task = cur.fetchone()
        cur.close()
        return (task)

    def register_model(self, username, password):
        conn = Connect().connect()
        cur = conn.cursor()
        cur.execute("INSERT INTO user(username, password) VALUES (%s, %s)", (username, password))
        conn.commit()
        cur.close()

    def login_model(self, username):
        conn = Connect().connect()
        cur = conn.cursor()
        result = cur.execute("SELECT * FROM user WHERE username = %s", username)
        if result > 0:
            data = cur.fetchone()
        else:
            data = 0
        cur.close()
        return (data)

    def dashboard_model(self):
        conn = Connect().connect()
        cur = conn.cursor()
        result = cur.execute("SELECT * FROM task")
        if result > 0:
            tasks = cur.fetchall()
        else:
            tasks = 0
        cur.close()
        return (tasks)

    def add_task_model(self, title):
        conn = Connect().connect()
        cur = conn.cursor()
        cur.execute("INSERT INTO task(title) VALUES(%s)", (title))
        conn.commit()
        cur.close()

    def edit_task_model_get(self, id):
        conn = Connect().connect()
        cur = conn.cursor()
        cur.execute("SELECT * FROM task WHERE task_id = %s", id)
        tasks = cur.fetchone()
        return (tasks)

    def edit_task_model_post(self, title, id):
        conn = Connect().connect()
        cur = conn.cursor()
        cur.execute("UPDATE task SET title = %s WHERE task_id = %s", (title, id))
        conn.commit()
        cur.close()

    def delete_task_model(self, id):
        conn = Connect().connect()
        cur = conn.cursor()
        cur.execute("DELETE FROM user_has_task WHERE fk_task_id = %s", (id))
        cur.execute("DELETE FROM task WHERE (task_id = %s)", (id))
        conn.commit()
        cur.close()