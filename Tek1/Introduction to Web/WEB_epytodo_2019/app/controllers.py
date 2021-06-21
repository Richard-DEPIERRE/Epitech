# -*- coding: utf-8 -*-
from app import *
from app.models import *
from app.api import *
from flask import *

class RegisterForm(Form):
    username = StringField('Username', [validators.Length(min=4, max=25)])
    password = PasswordField('Password', [
        validators.DataRequired(),
        validators.EqualTo('confirm', message='Mot de pass ne correspondent pas')
    ])
    confirm = PasswordField('Confirm Password')

class TaskForm(Form):
    title = StringField('Title', [validators.Length(min=1, max=200)])

class Controller():
    def index(self):
        return render_template("home.html")

    def tasks(self):
        tasks = API().api_tasks()
        if tasks:
            return render_template('tasks.html', tasks=tasks)
        else:
            msg = "No tasks found"
            return render_template('tasks.html', msg=msg)

    def task(self, id):
        tasks = API().api_task(id)
        return render_template('task.html', tasks=tasks)

    def register(self, request):
        form = RegisterForm(request.form)
        API().api_register(request, form)
        return render_template('register.html', form=form)

    def login(self, request):
        API().api_login(request)
        return render_template('login.html')

    def logout(self):
        session.clear()
        flash("You are logged out", 'success')
        return redirect(url_for("route_login"))

    def dashboard(self):
        tasks = API().api_dashboard()
        if tasks > 0:
            return render_template('dashboard.html', tasks=tasks)
        else:
            msg = "No tasks found"
            return render_template('dashboard.html', msg=msg)

    def add_task(self, request):
        form = TaskForm(request.form)
        API().api_add_task(request, form)
        return render_template('add_task.html', form=form)

    def edit_task(self, request, id):
        form = TaskForm(request.form)
        tasks = Model().edit_task_model_get(id)
        form.title.data = tasks['title']
        API().api_edit_task(request, form, id)
        return render_template('edit_task.html', form=form)

    def delete_task(self, id):
        API().api_delete_task(id)
        flash('Task Deleted', 'success')
        return redirect(url_for('route_dashboard'))