from django.urls import path
from app1 import views 

urlpatterns=[
    path('firstapp/',views.app1_func1)
]

