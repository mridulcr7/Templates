function setFormMessage(formElement, type, message) {
    const messageElement = formElement.querySelector(".form_msg ");

    messageElement.textContent = message;
    messageElement.classList.remove(".form__msg_success", ".form__msg_error");
    messageElement.classList.add(`form__msg${type}`);
}

function setInputError(inputElement, message) {
    inputElement.classList.add(".input_err_msg");
    inputElement.parentElement.querySelector(".input_err").textContent = message;
}

function clearInputError(inputElement) {
    inputElement.classList.remove(".input_err_msg");
    inputElement.parentElement.querySelector(".input_err").textContent = "";
}

document.addEventListener("DOMContentLoaded", () => {
    const loginForm = document.querySelector("#login");
    const createAccount = document.querySelector("#createAccount");

    document.querySelector("#linkCreateAccount").addEventListener("click", e => {
        e.preventDefault();
        login.classList.add("hide");
        createAccount.classList.remove("hide");
    });

    document.querySelector("#linkLogin").addEventListener("click", e => {
        e.preventDefault();
        login.classList.remove("hide");
        createAccount.classList.add("hide");
    });

    loginForm.addEventListener("submit", e => {
        e.preventDefault();

        setFormMessage(loginForm, "error", "Invalid username or password");
    });

    document.querySelectorAll(".input").forEach(inputElement => {
        inputElement.addEventListener("blur", curr => {
            if (curr.target.id === "password" && curr.target.value.length > 0 && curr.target.value.length < 8) {
                setInputError(inputElement, "Password must be at least 8 characters in length");
            }
        });

        inputElement.addEventListener("input", curr => {
            clearInputError(inputElement);
        });
    });
});