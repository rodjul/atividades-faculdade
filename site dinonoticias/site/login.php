<?php
include "php/banco_conexao.php";

$login = $_POST['login'];
$senha = $_POST['senha'];

//$error = 0;

/*
$resultado = mysqli_query($conexao, "SELECT nome,senha,foto from bancosite WHERE nome= '$nome' and senha= '$senha'") or die("Error:".mysqli_error($conexao));*/



$query = "SELECT nome, login, senha FROM usuarios WHERE nome=? AND senha=?";
if($stmt = mysqli_prepare($conexao, $query)){
    mysqli_stmt_bind_param($stmt, "ss", $login, $senha);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_bind_result($stmt, $nome, $usuario, $password);
    mysqli_stmt_fetch($stmt);
    
    
    
    if(isset($login) == $usuario && isset($senha) == $password){
        //echo "BEM VINDO";
        header('Location:index.php');
        echo "<br/><a href='index.html'>Voltar</a>";
    }else{
        //echo "Login ou senha incorretos";
        //echo "<br/><a href='index.html'>Voltar</a>";
        header('Location: cadastrase.php');
        
    }
    
    $stmt -> close();
}else{
    //echo "Falha no login";
    header('Location: cadastrase.php');
    //echo "<br/><a href='index.html'>Voltar</a>";
}

$conexao -> close();
        
     

?>